/*************************************************************************
	Topic C Project - CS M10B

	Spring 2012

	Topic B Project modified for operator overloading

	HugeInteger class implementation file
************************************************************************/

#include <iostream>
#include <cctype>

using namespace std;
#include"negativeResult.h"
#include "HugeInteger.h"

const size_t HugeInteger::DEFAULTSIZE = 40;
int HugeInteger::SUCCESS = 0;
int HugeInteger::FILE_PROBLEM = 1;
int HugeInteger::INVALID_DIGIT = 2;


HugeInteger::HugeInteger()
{
	arr = new int[ DEFAULTSIZE ];

	size = DEFAULTSIZE;
	
	initialize();
}

HugeInteger::HugeInteger( const HugeInteger &hi )
{
	arr = NULL;
	*this = hi;
}

void HugeInteger::initialize()
{
	for ( size_t pos = 0; pos < size; pos++ )
		arr[ pos ] = 0;
}


int HugeInteger::numberInput( string number ) 
{
	int rc = SUCCESS, val;

	size_t pos;

	// first check if input is a valid number
	for ( pos = 0; pos < number.size(); pos++ )
	{
		if ( !isdigit( number[ pos ] ) )
			rc = INVALID_DIGIT;
	}

	// put values in array - ignore leading 0s
	if ( rc == SUCCESS )
	{
		resize( number.size() );

		for ( pos = 0 ; pos < number.size(); pos++ )
		{
			val = static_cast<int>( number[ pos ] ) - '0';
			arr[ pos ] = val;
		}
	}
				
	return rc;
}

const HugeInteger& HugeInteger::operator = ( const HugeInteger &hi )
{
	if ( this == &hi )
		return *this;

	delete [] arr;
	size = hi.size;
	arr = new int[ size ];

	for ( size_t i = 0; i < size; ++i )
		arr[ i ] = hi.arr[ i ];

	return *this;
}


HugeInteger HugeInteger::operator + ( const HugeInteger &hir ) const
{
	int *tempArr, carry;
	size_t pos, pos2, tempSize;

	HugeInteger hi;

	if ( size >= hir.size )
	{
		hi.resize( size + 1 );  // in case of carry
		for ( pos = 1, pos2 = 0; pos2 < size; ++pos, ++pos2 )
			hi.arr[ pos ] = arr[ pos2 ];
		tempSize = hir.size;
		tempArr = new int[ tempSize ];
		for ( pos = 0; pos < tempSize; ++pos )
			tempArr[ pos ] = hir.arr[ pos ];
	}
	else
	{
		hi.resize( hir.size + 1 );  // in case of carry
		for ( pos = 1, pos2 = 0; pos2 < hir.size; ++pos, ++pos2 )
			hi.arr[ pos ] = hir.arr[ pos2 ];
		tempSize = size;
		tempArr = new int[ tempSize ];
		for ( pos = 0; pos < tempSize; ++pos )
			tempArr[ pos ] = arr[ pos ];
	}


	hi.arr[ 0 ] = 0;  // carry position

	for ( pos = hi.size, pos2 = tempSize, carry = 0; pos2 > 0; --pos, --pos2 )
	{
		hi.arr[ pos - 1 ] = hi.arr[ pos - 1 ] + tempArr[ pos2 - 1 ] + carry;
		if ( hi.arr[ pos - 1 ] >= 10 )
		{
			hi.arr[ pos - 1 ] -= 10;
			carry = 1;
		}
		else
			carry = 0;
	}

	for ( ; carry && pos > 0; --pos )
	{
		hi.arr[ pos - 1 ] += carry;
		if ( hi.arr[ pos - 1 ] >= 10 )
		{
			hi.arr[ pos - 1 ] -= 10;
			carry = 1;
		}
		else
			carry = 0;
	}

	delete [] tempArr;

	hi.resize();

	return hi;
}

HugeInteger HugeInteger::operator - ( const HugeInteger &hir ) const
{
// Responsibility of the client to ensure that the result is not negative
//  This should really be done by the class as an incorrect result should never be returned
//  When we cover exceptions, we will see how to handle cases like this
//  Assume, then, that the invoking object is always > the right operand
try{
	if(this->getSize() < hir.getSize())
throw negativeResult();
}
	
	catch(negativeResult &x)
	{
{cout<<"exception occured "<<endl<<x.what();}
	}


	size_t pos, pos2; 
	int num;
	bool borrow;

	HugeInteger hi;

	hi.resize( size );
	for ( pos = 0; pos < size; ++pos )
		hi.arr[ pos ] = arr[ pos ];

	for ( pos = size, pos2 = hir.size, borrow = false; pos > 0 && pos2 > 0; --pos, --pos2 )
	{
		if ( borrow )
			--( hi.arr[ pos - 1 ] );

		if ( hi.arr[ pos - 1 ] < hir.arr[ pos2 - 1 ] )
		{
			num = 10;
			borrow = true;
		}
		else
		{
			num = 0;
			borrow = false;
		}

		hi.arr[ pos - 1 ] = hi.arr[ pos - 1 ] + num - hir.arr[ pos2 - 1 ];
	}

	for ( ; borrow && pos > 0; --pos )
	{
		--( hi.arr[ pos - 1 ] );

		if ( hi.arr[ pos - 1 ] == -1 )
		{
			hi.arr[ pos - 1 ] = 9;  // borrow is sill true
		}
		else
			borrow = false;
	}

	hi.resize();

	return hi;
}


bool HugeInteger::operator ==( const HugeInteger &hir ) const
{
	size_t pos = 0, pos2 = 0;
	bool end;

	if ( ( size - pos ) != ( hir.size - pos2 ) )
		return false;

	for ( end = false; !end && pos < size; ++pos, ++pos2 )
		if ( arr[ pos ] != hir.arr[ pos2 ] )
			end = true;

	if ( !end )
		return true;
	else
		return false;
}

bool HugeInteger::operator != ( const HugeInteger &hir ) const
{
	return !( *this == hir );
}

bool HugeInteger::operator > ( const HugeInteger &hir ) const
{
	size_t pos = 0, pos2 = 0;
	bool end, gt;

	if ( ( size - pos ) > ( hir.size - pos2 ) )
		return true;

	if ( ( size - pos ) < ( hir.size - pos2 ) )
		return false;

	if ( *this == hir ) // check for equality 
		return false;

	for ( end = false, gt = true; !end && pos < size; ++pos, ++pos2 )
		if ( arr[ pos ] < hir.arr[ pos2 ] )
		{
			end = true;
			gt = false;
		}
		else
			if ( arr[ pos ] > hir.arr[ pos2 ] )
				end = true;

	return gt;

}

bool HugeInteger::operator >= ( const HugeInteger &hir ) const
{
	return ( ( *this == hir ) || ( *this > hir ) );
}

bool HugeInteger::operator < ( const HugeInteger &hir ) const
{
	return ( !( (*this == hir ) || ( *this > hir ) ) );
}
	
bool HugeInteger::operator <= ( const HugeInteger &hir ) const
{
	return !( *this > hir );
}


/*  The return value does not really work
	It only can be used since the values in the array must be positive
	Again, the real solution is to use exceptions
*/

int HugeInteger::operator [] ( size_t pos ) const
{
	if ( pos >= size || pos < 0 )
		return -1;

	else return arr[ pos ];
}

ostream & operator << ( ostream &out, const HugeInteger &hi )
{
	size_t pos = 0;

	if ( pos == hi.getSize() )
		out << 0 << endl;

	for ( ; pos < hi.getSize(); ++pos )
		out << hi[ pos ];

	out << endl;

	return out;
}

// What major assumption is being made in this function?
bool HugeInteger::resize( size_t newSize )
{
	if ( newSize < 1 )
		return false;

	if ( size == newSize )
		return true;  // is this the correct return?

	int *temp = new int[ newSize ];

	size_t len = ( newSize < size ) ? newSize : size;

	for ( size_t pos = 0; pos < len; pos++ )
		temp[ pos ] = arr[ pos ];

	delete [] arr;
	size = newSize;
	arr = temp;

	return true;
}


// gets rid of leading zeros
bool HugeInteger::resize()
{
	int newSize;
	size_t pos = firstNonZeroPos();

	if ( pos == size )
	{
		newSize = 1;
		--pos;
	}
	else
		newSize = size - pos;

	int *temp = new int[ newSize ];

	for ( size_t i = 0; pos < size; ++pos, ++i )
		temp[ i ] = arr[ pos ];

	delete [] arr;
	size = newSize;
	arr = new int[ size ];

	for ( pos = 0; pos < size; ++pos )
		arr[ pos ] = temp[ pos ];

	delete [] temp;

	return true;
}

size_t HugeInteger::firstNonZeroPos() const
{
	size_t pos;

	for ( pos = 0; pos < size && arr[ pos ] == 0; ++pos )
		;

	return pos;
}



