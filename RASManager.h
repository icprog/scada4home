/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef RASMANAGER_H
#define RASMANAGER_H

#include "Pop3Client.h"
#include "SMTPClient.h"
#include "LogTracer.h"
#include "SharedTypes.h"
#include "ItemRepository.h"
#include <sys/time.h>

class RASManager
{
  private:
    string _POP3Server;
    string _POP3User;
    string _POP3Password;
    SMTPClient *_SMTPClient;
    timeval _LastPop3Fetch;
    LogTracer *_Logger;
    pthread_t _ProcessingThread; 
    IRASEventSubscriber *_EventSubscriber;
    ItemRepository *_ItemRepo;
    void FetchPop3Mails();
    void SendMail(string argReceiverEmail,string argSubject,string argBodyText);
    void AnalyzeMail(Email argMail);
    void HandleAnalyzeError(Email argMail, string argText);
    void SendHelp(Email argMail);
    static void *LaunchMemberFunction(void *obj)
     {
	RASManager *targetObj = reinterpret_cast<RASManager *>(obj);
	return targetObj->ProcessingLoop();
     }
     
  public:
    bool Start();
    void Stop();
    void * ProcessingLoop();
    RASManager(ItemRepository *argItemRepo,IRASEventSubscriber *argEventSubsciber,string argPOP3Server,string argPOP3User,string argPOP3Password,LogTracer *argLogger);
    virtual ~RASManager();
};

#endif // RASMANAGER_H
