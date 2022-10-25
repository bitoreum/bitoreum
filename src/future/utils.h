// Copyright (c) 2021 The Bitoreum developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef _B_I_T_O_R_E_U_M__FUTILS_H
#define _B_I_T_O_R_E_U_M__FUTILS_H

//#include <vector>
//#include <stdint.h>
//#include "coins.h"
class Coin;
class COutPoint;
class CBlockIndex;

void maybeSetPayload(Coin& coin, const COutPoint& outpoint, const uint16_t& nType, const std::vector<uint8_t>& vExtraPayload);
//const char *validateFutureCoin(const std::vector<uint8_t>& payload, int maturity, uint32_t confirmedTime);

#endif //_B_I_T_O_R_E_U_M__FUTILS_H
