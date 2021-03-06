/*
 * ======================================================================
 * Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.
 * Licensed under the MIT License.
 * See LICENSE.md in the project root for license information.
 * ======================================================================
*/

#include <algorithm>
#include <vector>
#include "DocumentTrackingConsentManager.h"
#include "../ModernAPI/ConsentResult.h"
#include "../ModernAPI/IConsent.h"

namespace rmscore {
namespace consent {

DocumentTrackingConsentManager::DocumentTrackingConsentManager(std::shared_ptr<modernapi::IConsent> consent, bool /*isAutoApproved*/)
  : m_consent(consent)
//  , m_approved(isAutoApproved)
{}

bool DocumentTrackingConsentManager::ShouldGetConsent()
{
  /*  if (ConsentDBHelper::GetInstance().Initialize() &&
        (m_consent->Domain != nullptr))
     {
      return !(m_approved ||
               ConsentDBHelper::GetInstance().IsDocumentTrackingConsentnPresent(
                 m_consent
                 ->
                 User->Data(), m_consent->Domain->Data()));
     }*/

  return false;
}

void DocumentTrackingConsentManager::PersistConsentResult(const modernapi::ConsentResult &result)
{
  if (result.ShowAgain() || (m_consent->Domain().empty())) return;

  /*  if (ConsentDBHelper::GetInstance().Initialize())
     {
      ConsentDBHelper::GetInstance().AddDocumentTrackingConsent(
        m_consent->User->Data(),
        m_consent->Domain->Data());
     }*/
}
} // namespace consent
} // namespace rmscore
