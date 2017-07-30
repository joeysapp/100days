#include "Tower.h"

void Tower::addNode(Node t_node){
	nodes.push(t_node); 
}

Node& Tower::removeNode(){
	Node& returning_node = nodes.top();
	nodes.pop();
	return returning_node;
}
