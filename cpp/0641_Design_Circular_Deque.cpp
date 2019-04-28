class MyCircularDeque
{
    using SIZE_TYPE = std::vector<int>::size_type;

    std::vector<int> m_circular_deque;
    SIZE_TYPE m_head = 0;
    SIZE_TYPE m_tail = 0;
    SIZE_TYPE m_cnt = 0;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) :
        m_head(k-1)
    {
        assert( 0 < k );
        m_circular_deque.resize(k);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if( isFull() ) return false;

        m_circular_deque.at(m_head) = value;

        if( 0 == m_head ) m_head = m_circular_deque.size()-1;
        else --m_head;

        ++m_cnt;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if( isFull() ) return false;

        m_circular_deque.at(m_tail) = value;

        m_tail = (m_tail+1) % m_circular_deque.size();
        ++m_cnt;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if( isEmpty() ) return false;

        m_head = (m_head+1) % m_circular_deque.size();
        --m_cnt;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if( isEmpty() ) return false;

        if( 0 == m_tail ) m_tail = m_circular_deque.size()-1;
        else --m_tail;

        --m_cnt;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if( isEmpty() ) return -1;

        return m_circular_deque.at( (m_head+1) % m_circular_deque.size() );
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if( isEmpty() ) return -1;

        if( 0 == m_tail ) return m_circular_deque.back();
        else return m_circular_deque.at(m_tail-1);
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return m_cnt == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return m_cnt == m_circular_deque.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
