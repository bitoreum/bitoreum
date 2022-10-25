// Copyright (c) 2018-2021 The Dash Core developers
// Copyright (c) 2020-2022 The Bitoreum developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef _B_I_T_O_R_E_U_M__QUORUMS_INIT_H
#define _B_I_T_O_R_E_U_M__QUORUMS_INIT_H

class CDBWrapper;
class CEvoDB;

namespace llmq
{

// Init/destroy LLMQ globals
void InitLLMQSystem(CEvoDB& evoDb, bool unitTests, bool fWipe = false);
void DestroyLLMQSystem();

// Manage scheduled tasks, threads, listeners etc.
void StartLLMQSystem();
void StopLLMQSystem();
void InterruptLLMQSystem();
} // namespace llmq

#endif //_B_I_T_O_R_E_U_M__QUORUMS_INIT_H
