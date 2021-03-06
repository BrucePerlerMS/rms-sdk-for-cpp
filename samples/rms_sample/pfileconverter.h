/*
 * ======================================================================
 * Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.
 * Licensed under the MIT License.
 * See LICENSE.md in the project root for license information.
 * ======================================================================
*/

#ifndef PFILECONVERTER_H
#define PFILECONVERTER_H
#include <iostream>
#include <TemplateDescriptor.h>
#include <ProtectedFileStream.h>
#include <memory>

class ITemplatesCallback {
public:

  virtual size_t SelectTemplate(
    std::vector<rmscore::modernapi::TemplateDescriptor>& templates) =
    0;
};


class PFileConverter {
public:

  PFileConverter();
  ~PFileConverter();

  static void ConvertToPFilePredefinedRights(
    const std::string                                & userId,
    std::shared_ptr<std::istream>                      inStream,
    const std::string                                & fileExt,
    std::shared_ptr<std::iostream>                     outStream,
    rmscore::modernapi::IAuthenticationCallback      & auth,
    rmscore::modernapi::IConsentCallback             & consent,
    const std::vector<rmscore::modernapi::UserRights>& userRights);
  static void ConvertToPFileTemplates(
    const std::string                          & userId,
    std::shared_ptr<std::istream>                inStream,
    const std::string                          & fileExt,
    std::shared_ptr<std::iostream>               outStream,
    rmscore::modernapi::IAuthenticationCallback& auth,
    rmscore::modernapi::IConsentCallback       & consent,
    ITemplatesCallback                         & templ);
  static std::shared_ptr<rmscore::modernapi::GetProtectedFileStreamResult>
  ConvertFromPFile(const std::string                          & userId,
                   std::shared_ptr<std::istream>                inStream,
                   std::shared_ptr<std::iostream>               outStream,
                   rmscore::modernapi::IAuthenticationCallback& auth,
                   rmscore::modernapi::IConsentCallback       & consent);

private:

  static void ConvertToPFileUsingPolicy(
    std::shared_ptr<rmscore::modernapi::UserPolicy>policy,
    std::shared_ptr<std::istream>                  inStream,
    const std::string                            & fileExt,
    std::shared_ptr<std::iostream>                 outStream);
};

#endif // PFILECONVERTER_H
