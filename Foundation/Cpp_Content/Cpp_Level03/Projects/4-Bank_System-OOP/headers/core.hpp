#ifndef CORE_HPP
#define CORE_HPP

#include "clsbankclient.hpp"

void ReadStr(clsBankClient &Client);
void UpdateClient();
void AddNewClient();
void DeleteClient();
void PrintClientRecordLine(clsBankClient Client);
void ShowClientsList();
void ShowClientsTotalBalancesList();
void PrintClientRecordBalanceLine(clsBankClient Client);

#endif /* CORE_HPP */
