#pragma once

#ifndef MAP_H
#define MAP_H

#include "TrackedObject.h"

#include <map>

template <class K, class T, typename Sort = std::less<K>>
class Map :
	public TrackedObject
{
public:

	typedef typename std::map<K, T>::iterator
        Iterator;
	typedef typename std::map<K, T>::reverse_iterator
        ReverseIterator;
	typedef typename std::map<K, T>::const_iterator
        ConstIterator;
	typedef typename std::map<K, T>::const_reverse_iterator
        ConstReverseIterator;

	typedef std::pair<K, T> Pair;

    inline Map( void ) :
        m_Map()
    { }

    inline Map( const Map& rhs ) :
        m_Map(rhs.m_Map)
    { }

    virtual inline ~Map( void ) { clear(); }

	virtual inline string getClassName( void ) const { return "Map"; }

    inline void add( const K& key, const T& item )
        { m_Map.insert(Pair(key, item)); }

    inline void clear( void ) { m_Map.clear(); }

    inline void removeAt( const K& key )
		{ m_Map.erase(key); }

    inline T& at( const K& key )       { return m_Map[key]; }
    inline T& at( const K& key ) const { return m_Map[key]; }
	inline T& operator[]( const K& key )	   { return at(key); }
	inline T& operator[]( const K& key ) const { return at(key); }

    inline bool containsKey( const K& key )
		{ return (m_Map.find(key) != cend()); }
    bool containsKey( const T& value ) const;

    inline bool isEmpty( void ) const
        { return m_Map.empty(); }

    K indexOf( const T& item ) const;

    inline size_t size( void ) const { return m_Map.size(); }

    inline Iterator find( const K& key )
        { return m_Map.find(key); }

    inline ConstIterator find( const K& key ) const
        { return m_Map.find(key); }

    inline void insert( Iterator& first, Iterator& last )
        { m_Map.insert(first, last); }

    inline void insert( ConstIterator& first,
                        ConstIterator& last ) const
        { m_Map.insert(first, last); }

    inline Iterator begin( void )
        { return m_Map.begin(); }

    inline Iterator end( void )
        { return m_Map.end(); }

    inline ReverseIterator rbegin( void )
        { return m_Map.rbegin(); }

    inline ReverseIterator rend( void )
        { return m_Map.rend(); }

    inline ConstIterator cbegin( void ) const
        { return m_Map.cbegin(); }

    inline ConstIterator cend( void ) const
        { return m_Map.cend(); }

    inline ConstReverseIterator crbegin( void ) const
        { return m_Map.crbegin(); }

    inline ConstReverseIterator crend( void ) const
        { return m_Map.crend(); }

private:

    std::map<K, T, Sort>    m_Map;

}; // class Map<T, K, Sort>

template <class K, class T, typename Sort>
bool Map<K, T, Sort>::containsKey( const T& value ) const
{
	for (auto it = ConstBegin(); it != ConstEnd(); ++it)
        if (it->second == value)
            return true;
    return false;
}

template <class K, class T, typename Sort>
K Map<K, T, Sort>::indexOf( const T& item ) const
{
	for (auto it = ConstBegin(); it != ConstEnd(); ++it)
        if (it->second == item)
            return it->first;
    return K();
}

#endif // MAP_H
