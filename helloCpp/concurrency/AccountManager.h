#pragma once
#include <mutex>

class Account {};

void transfer(Account& lhs, Account& rhs) {}

class AccountManager
{
public:
	AccountManager(Account const& acc) : m_Account(acc) {}

	~AccountManager() {}

	friend void transfer(AccountManager& lhs, AccountManager& rhs)
	{
		// attempt to acquire a lock on std::mutex when we already results in undefined behavior
		// check the arguments are different instances
		if (&lhs == &rhs)
		{
			return;
		}

		// std::lock() locks 2 mutexes
		// note that all locks will be released as long as a lock is unsucessfully acquired
		// when exception is thrown
		std::lock(lhs.m_Mutex, rhs.m_Mutex);

		// now construct lock_guards for each mutex
		// std::adopt_lock indicates the to lock_guard that the mutex
		// is already acquired and just take ownership on the existing lock
		// instead of acquiring a lock in its constructor.
		std::lock_guard<std::mutex> lock_lhs(lhs.m_Mutex, std::adopt_lock);
		std::lock_guard<std::mutex> lock_rhs(rhs.m_Mutex, std::adopt_lock);

		transfer(lhs.m_Account, rhs.m_Account); // now perform operation
	}

private:
	Account m_Account;
	std::mutex m_Mutex;
};

