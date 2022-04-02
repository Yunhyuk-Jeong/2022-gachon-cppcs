//* 202131230 정윤혁
//* 2022.04.02 Sat
//* Source Code

#include <Windows.h>
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <process.h>
#include <thread>
#include <vector>

using namespace std;

class CriticalSection
{
    CRITICAL_SECTION m_critiSec;

  public:
    CriticalSection();
    ~CriticalSection();

    void Lock();
    void Unlock();
};

class CriticalSectionLock
{
    CriticalSection *m_pCritSec;

  public:
    CriticalSectionLock(CriticalSection &critSec);
    ~CriticalSectionLock();
};

CriticalSection::CriticalSection()
{
    InitializeCriticalSectionEx(&m_critiSec, 0, 0);
}

CriticalSection::~CriticalSection()
{
    DeleteCriticalSection(&m_critiSec);
}

void CriticalSection::Lock()
{
    EnterCriticalSection(&m_critiSec);
}

void CriticalSection::Unlock()
{
    LeaveCriticalSection(&m_critiSec);
}

CriticalSectionLock::CriticalSectionLock(CriticalSection &critSec)
{
    m_pCritSec = &critSec;
    m_pCritSec->Lock();
}

CriticalSectionLock::~CriticalSectionLock()
{
    m_pCritSec->Unlock();
}
