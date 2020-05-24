// Code : Remove Min
// Send Feedback
// Implement the function RemoveMin for the min priority queue class.
// For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
// Note : main function is given for your reference which we are using internally to test the code.


//solution

#include <vector>

/*******************
* Main function - 
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**************************/


class PriorityQueue {
	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);
		
		int childIndex = pq.size() - 1;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}

    int removeMin() {
        // Complete this function
        int ans=pq[0];
      	pq[0]=pq[pq.size()-1];
      	pq.pop_back();
      	int size=pq.size();
      	int parentindex=0;
      	int childindex1=2*parentindex+1;
      	int childindex2=2*parentindex+2;
        while(childindex1<size-1){
			int minindex=(pq[childindex1]<pq[childindex2]?childindex1:childindex2);
       	 	minindex=pq[parentindex]<pq[minindex]?parentindex:minindex;
        	if(minindex!=parentindex){
          		int temp=pq[minindex];
          		pq[minindex]=pq[parentindex];
                pq[parentindex]=temp;
        	}
        	else
          		break;
          parentindex=minindex;
          childindex1=2*parentindex+1;
          childindex2=2*parentindex+2;
      	}
      return ans;
    }


};
