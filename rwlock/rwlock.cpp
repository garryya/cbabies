//============================================================================
// Name        : threads_rwlock.cpp
// Author      : GarryY
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "rwlock.h"

CRWLock::CRWLock()
{
    m_bWriting = false;
    m_nReaders = 0;
    pthread_mutex_init(&m_mutex, NULL);
    pthread_cond_init(&m_cv, NULL);
}

CRWLock::~CRWLock()
{
    pthread_mutex_destroy(&m_mutex);
    pthread_cond_destroy(&m_cv);
}

void CRWLock::write_lock()
{
    pthread_mutex_lock(&m_mutex);
    if( m_bWriting || m_nReaders )
        pthread_cond_wait(&m_cv, &m_mutex);
    m_bWriting = true;
    pthread_mutex_unlock(&m_mutex);
}

void CRWLock::write_unlock()
{
    pthread_mutex_lock(&m_mutex);
    if( m_bWriting )
    {
        m_bWriting = false;
        pthread_cond_broadcast(&m_cv);
    }
    pthread_mutex_unlock(&m_mutex);
}

void CRWLock::read_lock()
{
    pthread_mutex_lock(&m_mutex);
    if( m_bWriting )
        pthread_cond_wait(&m_cv, &m_mutex);
    m_nReaders++;
    pthread_mutex_unlock(&m_mutex);
}

void CRWLock::read_unlock()
{
    pthread_mutex_lock(&m_mutex);
    if( m_nReaders )
    {
        m_nReaders--;
        if( ! m_nReaders )
            pthread_cond_broadcast(&m_cv);
    }
    pthread_mutex_unlock(&m_mutex);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	cout << "rwlock" << endl; // prints rwlock
	return 0;
}
