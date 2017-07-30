#pragma once
#ifndef TOWER_H
#define TOWER_H

#include "Node.h"

class Tower { 
	public:
		Tower(){}
		int getSize(){ return nodes.size(); }
		void addNode(Node t_node);
		Node& removeNode();
	private:
		std::stack<Node> nodes;

};

#endif
