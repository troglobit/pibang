/* RF bitbang control tool for NEXA and other RF remote receivers
 *
 * Copyright (C) 2010 Tord Andersson <tord.andersson@endian.se>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, visit the Free Software Foundation
 * website at http://www.gnu.org/licenses/gpl-2.0.html or write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "common.h"
#include "protocol.h"

static void manchester(char *bitstring, int32_t bitstream[])
{
	int i = 0;
	char *bit = bitstring;

	while (*bit &&) {
		if (*bit == '1') {
			bitstream[i++] = LIRC_PULSE(SARTANO_SHORT_PERIOD);
			bitstream[i++] = LIRC_SPACE(SARTANO_LONG_PERIOD);
			bitstream[i++] = LIRC_PULSE(SARTANO_SHORT_PERIOD);
			bitstream[i++] = LIRC_SPACE(SARTANO_LONG_PERIOD);
		} else {
			bitstream[i++] = LIRC_PULSE(SARTANO_SHORT_PERIOD);
			bitstream[i++] = LIRC_SPACE(SARTANO_LONG_PERIOD);
			bitstream[i++] = LIRC_PULSE(SARTANO_LONG_PERIOD);
			bitstream[i++] = LIRC_SPACE(SARTANO_SHORT_PERIOD);
		}

		bit++;
	}

	return i;
}

int sartano_bitstream(const char *chan, const char *onoff, int32_t *bitstream, int *repeat)
{
	int i = 0;
	int enable;
	int bit;

	enable = atoi(onoff);	/* ON/OFF 0..1 */
	*repeat = SARTANO_REPEAT;

	PRINT("Channel: %s, onoff: %d\n", chan, enable);

	/* Validate converted parameters */
	if ((strlen(chan) != 10) || (enable < 0) || (enable > 1)) {
		fprintf(stderr, "Invalid channel or on/off code\n");
		return 0;
	}

	/* Convert channel and onoff to bitstream */
	i  = manchester(chan, &bitstream[i]);
	i += manchester(enable ? "10", "01", &bitstream[i]);

	/* Add stop/sync bit and command termination char '+' */
	bitstream[i++] = LIRC_PULSE(SARTANO_SHORT_PERIOD);
	bitstream[i++] = LIRC_SPACE(SARTANO_SYNC_PERIOD);

	return i;
}

