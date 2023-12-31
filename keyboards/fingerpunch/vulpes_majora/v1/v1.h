/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#define ___ KC_NO

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// With the shift register, define the columns in the order of A-H as defined in the schematic
#define LAYOUT_vulpes_majora( \
    K00, K01, K02, K03, K04, K05,                                K35, K34, K33, K32, K31, K30, \
    K10, K11, K12, K13, K14, K15,                                K45, K44, K43, K42, K41, K40, \
    K20, K21, K22, K23, K24, K25,                                K55, K54, K53, K52, K51, K50, \
                        K06, K16, K26,    K62, K63, K64,    K56, K46, K36, \
         K71,           K07, K17, K27,                      K37, K47, K57,           K81, \
    K72, K76, K74,                                                              K82, K86, K84, \
         K73,                                                                        K83 \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57 }, \
    { ___, ___, K62, K63, K64, ___, ___, ___ }, \
    { ___, K71, K72, K73, K74, ___, K76, ___ }, \
    { ___, K81, K82, K83, K84, ___, K86, ___ } \
}
