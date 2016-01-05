#include <iostream>
#include "list.h"

List::List() {
    sizee = 0;
    first = nullptr;
}

List::~List() {
	Node* temp = first;
	Node* before;
	for(int i = 0; i < size(); i++){
		before = temp;
		temp = temp->next;
		delete before;
	}
}

bool List::exists(int d) const {
    Node* temp = first;
    for(int i = 0; i < size(); i++) {
		if(d == temp->value) {
	    	return true;
		}
		temp = temp->next;
    }
    return false;
}

int List::size() const {
	return sizee;
}

bool List::empty() const {
	return size() == 0;
}

void List::insertFirst(int d) {
    if(size() == 0) {
		first = new Node(d, nullptr);
    } else {
        Node* temp = new Node(d, first);
		first = temp;
    }
    ++sizee;
}

void List::remove(int d, DeleteFlag df) {
    Node* temp = first;
    Node* before;
    if (size() == 0) {
		// do nothing
    }
    if (size() == 1) {
		delete first;
		--sizee;
    } else {
	    if(DeleteFlag::LESS == df) {
		for(int i = 0; i < size(); i++) {
		    if(d > temp->value) {
			if(i == 0) {
			    first = first->next;
			    delete temp;
			    --sizee;
			    break;
			} else {
			    before->next = temp->next;
			    delete temp;
			    --sizee;
			    break;
			}
	    }
	    before = temp;
	    temp = before->next;
		}
	}

	    if(DeleteFlag::EQUAL == df) {
		for(int i = 0; i < size(); i++) {
		   
		    if(d == temp->value) {
				if(i == 0) {
				    first = first->next;
			    	delete temp;
			    	--sizee;
			    	break;
				} else {
				    before->next = temp->next;
			    	delete temp;
			    	--sizee;
			    	break;
				}
		    }
		    before = temp;
		    temp = before->next;
			}
	    }

	    if(DeleteFlag::GREATER == df) {
		for(int i = 0; i < size(); i++) {
		    if(d < temp->value) {
			if(i == 0) {
			    first = first->next;
			    delete temp;
			    --sizee;
			    break;
			} else {
			    before->next = temp->next;
			    delete temp;
			    --sizee;
			    break;
			}

		    }
		    before = temp;
		    temp = before->next;
		}
	    }
    }
}

void List::print() const {
	std::cout << std::endl;
	Node* temp = first;
	for(int i = 0; i < size(); i++){
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}

}

