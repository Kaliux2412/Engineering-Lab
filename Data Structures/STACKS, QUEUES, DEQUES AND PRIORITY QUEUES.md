- ~ Stack: Used for the newest like if you want to go back in your cellphone.
	- Only top is visible, push(x) puts x on the top, pop() removes the top. - `getTop()` reads it without removing it. 
	- top = -1 means no elements.
	- Stack on a fixed array:
```
	bool push(int x) {
	    if (top == MAX - 1) return false;   // full: x is lost
	    data[++top] = x;
	    return true;
	}
	bool pop() {
	    if (top == -1) return false;        // empty
	    --top;                              // no need to erase
	    return true;
	}
	int getTop() const { return data[top]; } 
```
- ~ Queue: For the oldest, like for example in a playlists that you have in spotify, when you play it it start with the oldest record you have.
	- FIFO: fist in, first out. Like a line at the supermarket.
	- enqueue(x): adds something at the back.
	- dequeue(x): removes the front.
	- Circular Queue:
```
	- 
	- bool enqueue(int x) {
	    if (count == MAX) return false;        // full
	    data[(front + count) % MAX] = x;       // the back slot
	    ++count;
	    return true;
	}
	bool dequeue() {
	    if (count == 0) return false;          // empty
	    front = (front + 1) % MAX;             // wrap around
	    --count;
	    return true;
	}
```
- ~ Deque: To keep only your las N items or like either elements,  the lastest or the newest.
	- Uses Double Linklist

- ! Priority Queue: the most urgent like for example in a map you want the fastest route.
- Leaves the first, not the oldest. Stores elements. insert(x) adds one; extractMin(x)removes the most urgent one.