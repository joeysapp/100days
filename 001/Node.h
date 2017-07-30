#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
	public:
		int getSize() const { return m_size; }
		Node(int t_size) : m_size { t_size } {}
	private:
		const int m_size { 0 };
};

#endif
