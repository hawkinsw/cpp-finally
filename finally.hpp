#ifndef _FINALLY_HPP
#define _FINALLY_HPP

#include <functional>

#define Try [&]()
#define Finally [&]()
typedef std::function<void (void)> Block;
class TryFinally {
	public:
		TryFinally(Block t, Block f) : m_try(t), m_finally(f) {
			m_try();
		};
		~TryFinally() { m_finally(); };
	private:
		Block m_finally, m_try;
};
#endif
