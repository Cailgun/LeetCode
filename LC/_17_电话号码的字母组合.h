#pragma once
#include <vector>
#include <string>
#include <memory>
class _17电话号码的字母组合
{
	class Solution {
	public:

		class Node
		{
		public:
			Node() : _parent(nullptr) {}

			std::string GetString()
			{
				std::string str = "";
				auto p = this;
				while (p->GetParent())
				{
					str += p->GetCh();
					p = p->GetParent();
				}

				reverse(str.begin(), str.end());
				return str;
			}

			std::vector<Node*> GetChild()
			{
				return _children;
			}

			Node* GetParent()
			{
				return _parent;
			}

			char GetCh()
			{
				return _ch;
			}

			void SetCh(char ch)
			{
				_ch = ch;
			}

			void SetParent(Node* parent)
			{
				_parent = parent;
				parent->AddChild(this);
			}

			void AddChild(Node* child)
			{
				_children.push_back(child);
			}

			bool HasChild()
			{
				return _children.size();
			}
		private:
			char _ch;
			std::vector<Node*> _children;
			Node* _parent;
		};

		class Tree
		{
		public:
			Tree() :_root(new Node()) {}
			~Tree()
			{
				std::vector<Node*> all;
				GetAll(_root, all);
				for (auto iter : all)
				{
					delete iter;
					iter = nullptr;
				}
			}

			void DeepSearch(Node* node, std::vector<Node*>& vec)
			{
				if (node->HasChild())
				{
					for (auto& iter : node->GetChild())
					{
						DeepSearch(iter, vec);
					}
				}
				else
				{
					vec.push_back(node);
					return;
				}
			}

			Node* GetRoot()
			{
				return _root;
			}

		private:
			void GetAll(Node* node, std::vector<Node*>& vec)
			{
				vec.push_back(node);
				if (node->HasChild())
				{
					for (auto& iter : node->GetChild())
					{
						GetAll(iter, vec);
					}
				}
			}

			Node* _root;
		};
		static std::vector<std::string> letterCombinations(std::string digits) {
			std::shared_ptr<Tree> t(new Tree());
			std::vector<std::string> ret;

			for (auto character : digits)
			{
				std::vector<Node*> vec;
				switch (character)
				{
				case '2':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						a->SetCh('a');
						b->SetCh('b');
						c->SetCh('c');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
					}
				}
				break;
				case '3':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						a->SetCh('d');
						b->SetCh('e');
						c->SetCh('f');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
					}
				}
				break;
				case '4':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						a->SetCh('g');
						b->SetCh('h');
						c->SetCh('i');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
					}
				}
				break;
				case '5':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						a->SetCh('j');
						b->SetCh('k');
						c->SetCh('l');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
					}
				}
				break;
				case '6':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						a->SetCh('m');
						b->SetCh('n');
						c->SetCh('o');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
					}
				}
				break;
				case '7':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						Node* d = new Node();
						a->SetCh('p');
						b->SetCh('q');
						c->SetCh('r');
						d->SetCh('s');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
						d->SetParent(iter);
					}
				}
				break;
				case '8':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						a->SetCh('t');
						b->SetCh('u');
						c->SetCh('v');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
					}
				}
				break;
				case '9':
				{
					t->DeepSearch(t->GetRoot(), vec);

					for (auto iter : vec)
					{
						Node* a = new Node();
						Node* b = new Node();
						Node* c = new Node();
						Node* d = new Node();
						a->SetCh('w');
						b->SetCh('x');
						c->SetCh('y');
						d->SetCh('z');
						a->SetParent(iter);
						b->SetParent(iter);
						c->SetParent(iter);
						d->SetParent(iter);
					}
				}
				}
			}

			std::vector<Node*> vec;
			t->DeepSearch(t->GetRoot(), vec);
			if (vec.size() == 1)
			{
				return ret;
			}
			for (auto iter : vec)
			{
				ret.push_back(iter->GetString());
			}

			return ret;
		}
	};
};

