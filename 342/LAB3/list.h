//----------------------------------------------------------------------------
// merge
template <typename T> 
void List<T>::merge(List& lhs, List& rhs){
	///if (*this != lhs || *this != rhs){
		this->makeEmpty();
	//}
	
	
		Node * tempHead = new Node;
		
		Node * tempHeadInsert = tempHead; 
	
	Node * lhsTransverse = lhs.head;
	Node * rhsTransverse = rhs.head;
	

	while (lhsTransverse != NULL || rhsTransverse != NULL){
		if (lhsTransverse != NULL && rhsTransverse != NULL){
			if (*lhsTransverse->data < *rhsTransverse->data){
				tempHead->next = lhsTransverse;
				lhsTransverse = lhsTransverse->next;
				tempHead = tempHead->next;

			}
			else if (*lhsTransverse->data > *rhsTransverse->data){
				tempHead->next = rhsTransverse;
				rhsTransverse = rhsTransverse->next;
				tempHead = tempHead->next;
			}
			else {
				tempHead->next = lhsTransverse;
				lhsTransverse = lhsTransverse->next;
				tempHead = tempHead->next;

			}
		}
		else if (lhsTransverse == NULL){
			tempHead->next = rhsTransverse; 
			rhsTransverse = rhsTransverse->next; 
			tempHead = tempHead->next;

		}
		else{
			tempHead->next = lhsTransverse;
			lhsTransverse = lhsTransverse->next;
			tempHead = tempHead->next;

		}

	}
	head = tempHeadInsert->next;
	delete tempHeadInsert; 

	
	lhs.head = NULL; 
	rhs.head = NULL; 

	

}
