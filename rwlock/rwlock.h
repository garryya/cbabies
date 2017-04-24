/*
 * rwlock.h
 *
 *  Created on: Apr 4, 2015
 *      Author: garry
 */

#ifndef RWLOCK_H_
#define RWLOCK_H_

#include <pthread.h>

class CRWLock {

    protected:
        bool m_bWriting;
        int m_nReaders;
        pthread_mutex_t m_mutex;
        pthread_cond_t m_cv;

    public:

        CRWLock();
        ~CRWLock();

        void write_lock();
        void write_unlock();

        void read_lock();
        void read_unlock();
};




#endif /* RWLOCK_H_ */
