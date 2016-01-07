/*
 * Copyright (c) 2013, Oculus Technologies Inc. All rights reserved.
 * Three Ocean (to@bcloud.us)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _UDSCOMMANDAPPPROTOCOLHANDLER_H
#define _UDSCOMMANDAPPPROTOCOLHANDLER_H

#ifdef HAS_PROTOCOL_UNIXDOMAIN_SOCKET
#include "protocols/unixdomainsocket/baseuxdomainsocketappprotocolhandler.h"

class BaseStream;
namespace app_qicstreamer {
  class UDSCommandAppProtocolHandler
    : public BaseUXDomainSocketAppProtocolHandler
  {
    private:
    public:
      UDSCommandAppProtocolHandler(Variant &configuration);
      virtual ~UDSCommandAppProtocolHandler();
      virtual bool ProcessMessage(BaseProtocol *pProtocol, IOBuffer &buffer);
      // observer interface
      virtual bool OnMessage(BaseUDSMessageProtocol *pProtocol, Variant &message);
      virtual bool OnData(UDS_MESSAGE_TYPE type, uint8_t *pData, uint32_t length, uint64_t ts);
  };

}
#endif

#endif /* _UDSCOMMANDAPPPROTOCOLHANDLER_H */

