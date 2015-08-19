#pragma once 

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "TrackedObject.h"

#include <vector>

/// List of objects backed by an Array
/*!
 * Wrapper for std::vector with added functionality and standardized function
 * names. 
 */
template <class T>
class ArrayList :
	public TrackedObject
{
public:

	typedef typename std::vector<T>::iterator
		Iterator;
	typedef typename std::vector<T>::reverse_iterator
		ReverseIterator;
	typedef typename std::vector<T>::const_iterator
		ConstIterator;
	typedef typename std::vector<T>::const_reverse_iterator
		ConstReverseIterator;

    inline ArrayList( void ) :
        m_List()
    { }

    inline ArrayList( const ArrayList& rhs ) :
        m_List(rhs.m_List)
    { }
																			   
    virtual inline ~ArrayList( void ) { clear(); }

	virtual inline string getClassName( void ) const { return "Array List"; }

	/// Add a new element to the list
	/*! 
	 * \param item The item to be added to the list
	 */
    inline void add( const T& item )
        { m_List.push_back(item); }

	/// Clear the list of all elements
    inline void clear( void ) { m_List.clear(); }

	/// Returns the element at the given index
	/*!
	 * \param index The index to get the element from
	 * \returns The element at the given index
	 */
    inline       T& at( const int& index )       { return m_List[index]; }

	/// Returns the element at the given index
	/*!
	* \param index The index to get the element from
	* \returns The element at the given index
	*/
    inline const T& at( const int& index ) const { return m_List[index]; }

	/// Returns the element at the given index
	/*!
	* \param index The index to get the element from
	* \returns The element at the given index
	*/
	inline       T& operator[]( const int& index )       { return at(index); }

	/// Returns the element at the given index
	/*!
	 * \param index The index to get the element from
	 * \returns The element at the given index
	 */
	inline const T& operator[]( const int& index ) const { return at(index); }

	// TODO: Implement Data()

	/// Returns if the given element exists within the list
	/*! 
	 * \param item The item to look for in the list
	 * \returns True if the element is in the list, False otherwise
	 */
	inline bool contains( T item ) const
		{ return (isEmpty() ? false : 
			std::find(cbegin(), cend(), item) != cend()); }

	/// Returns if the given index exists within the list
	/*!
	 * \param index The index to check against the bounds of the list
	 * \returns True if the index is in the list, False otherwise
	 */
	inline bool hasIndex( const unsigned int& index ) const
		{ return (isEmpty() ? false : (index >= 0 && index <= size() - 1)); }

	/// Returns the index of a given element, or -1 if not found
	/*!
	* \param item The element to get the index of
	* \returns The index of the element, or -1 if it could not be found
	*/
	unsigned int indexOf( const T& item ) const;

	/// Returns if the list is empty
	/*!
	* \returns True if the list is empty, False otherwise
	*/
    inline bool isEmpty( void ) const
        { return m_List.empty(); }

	/// Returns the size of the array
	/*!
	* \returns The size of the array
	*/
    inline size_t size( void ) const { return m_List.size(); }

	/// Resizes the internal capacity of the array
	/*!
	* Resizes the internal capacity of the array, which will remove elements if
	* the new capacity is less than the current size of the array, but will not
	* add any new elements if the capacity is larger than the current size of
	* the array.
	* \param size The new internal size of the array
	*/
	inline void resize( const unsigned int& size ) 
		{ m_List.resize(size); }

    inline void insert( Iterator& first, Iterator& last )
        { m_List.insert(first, last); }

    inline void insert( ConstIterator& first,
                        ConstIterator& last ) const
        { m_List.insert(first, last); }

	inline void insertAt( const T& item, const unsigned int& index ) 
		{ m_List.insert(begin() + index, item); }

	inline T& front( void ) { return m_List.front(); }
	inline T& back ( void ) { return m_List.back(); }
	inline const T& front( void ) const { return m_List.front(); }
	inline const T& back ( void ) const { return m_List.back(); }

	inline T popBack ( void ) { return m_List.pop_back(); }

	inline Iterator remove( Iterator it ) { return m_List.erase(it); }
	inline Iterator remove( Iterator start, Iterator end ) 
		{ return m_List.erase(start, end); }

	bool remove( const T& item );

	/// Remove the element at the given index
	/*!
	 * \param index The index of the element to remove
	 * \returns True if the element exists and was removed, False otherwise
	 */
	inline bool removeAt( const unsigned int& index )
	{
		if ( ! hasIndex(index))
			return false;
		m_List.erase(begin() + index);
		return true;
	}

	inline bool removeBack( void ) 
	{ 
		if (isEmpty()) 
			return false; 
		popBack();
		return true; 
	}

	template <class InputIterator>
	inline void assign( InputIterator first, InputIterator last )
		{ m_List.assign(first, last); }

    inline Iterator begin( void )
        { return m_List.begin(); }

    inline Iterator end( void )
        { return m_List.end(); }

    inline ReverseIterator rbegin( void )
        { return m_List.rbegin(); }

    inline ReverseIterator rend( void )
        { return m_List.rend(); }

    inline ConstIterator cbegin( void ) const
        { return m_List.cbegin(); }

    inline ConstIterator cend( void ) const
        { return m_List.cend(); }

    inline ConstReverseIterator crbegin( void ) const
        { return m_List.crbegin(); }

    inline ConstReverseIterator crend( void ) const
        { return m_List.crend(); }

private:

	std::vector<T>		m_List;

}; // class ArrayList

template <class T>
unsigned int ArrayList<T>::indexOf(const T& item) const
{
	if (isEmpty())
		return -1;
	auto it = find(cbegin(), cend(), item);
	return (it == cend() ? -1 : it - cbegin());
}

template <class T>
bool ArrayList<T>::remove(const T& item)
{
	for (auto it = begin(); it != end(); ++it)
		if (*it == item)
		{
			remove(it);
			return true;
		}
	return false;
}

#endif // ARRAY_LIST_H