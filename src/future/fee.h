// Copyright (c) 2021 The Bitoreum developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef _B_I_T_O_R_E_U_M__FEE_H
#define _B_I_T_O_R_E_U_M__FEE_H

#include <amount.h>
#include <coins.h>

CAmount getFutureFeesCoin();
uint16_t getFutureFees();

//void maybeSetPayload(Coin& coin, const COutPoint& outpoint, const int16_t& nType, const std::vector<uint8_t>& vExtraPayload);

#endif //_B_I_T_O_R_E_U_M__FEE_H
