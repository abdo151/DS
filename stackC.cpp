//#include "stackC.h"
//
//template<typename StackEntry>
// stackC<StackEntry>::stackC():top(0)
//{
//}
//
//template<typename StackEntry>
//inline bool stackC<StackEntry>::full()
//{
//	return top == maxsize;
//}
//
//template<typename StackEntry>
//inline bool stackC<StackEntry>::empty()
//{
//	return !top;
//}
//
//template<typename StackEntry>
//void stackC<StackEntry>::push(StackEntry e)
//{
//	entry[top++] = e;
//}
//template<typename StackEntry>
//void  stackC<StackEntry>::pop(StackEntry *pe)
//{
//	*pe = entry[--top];
//}
//
//template<typename StackEntry>
//bool  stackC<StackEntry>::peek(StackEntry* pe,int pos)
//{
//	if (top < pos)
//		return 0;
//	*pe = entry[top - pos];
//	return 1;
//
//}
