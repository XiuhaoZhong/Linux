#ifndef __TQUEUE_H__
#define	__TQUEUE_H__

template <typename Type> 
class TQueue {
	public:
		// empty TQueue
		TQueue() : head_(0), tail_(0) {}
		// copy control to manage pointers to TQueueItems in the TQueue
		TQueue( const TQueue &tq) : head_(0), tail_(0) { copy_elems(tq); }

		TQueue& operator=(const TQueue&);
		~TQueue() { destroy(); }

		Type& front() { return head_->item; }
		const Type &front() const { return head_->item; }
		void push(const Type&);
		void pop();
		bool empty() const {
			return head_ == 0;
		}
		
	private:
		TQueueItem<Type> *head_;
		TQueueItem<Type> *tail_;

		void destroy();
		void copy_elems(const TQueue&);
}

#endif // __TQUEUE_H__
