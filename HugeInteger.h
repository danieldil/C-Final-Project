/*************************************************************************
	Topic C Project - CS M10B

	Spring 2014

	Topic B Project modified for operator overloading

	HugeInteger class header file
************************************************************************/

#include <string>

using namespace std;

class HugeInteger
{
public:
	HugeInteger();
	HugeInteger( const HugeInteger &hi );
	~HugeInteger() { delete [] arr; }

	int numberInput( string );

	HugeInteger operator + ( const HugeInteger &hi ) const;
	HugeInteger operator - ( const HugeInteger &hi ) const;
	const HugeInteger& operator = ( const HugeInteger &hi );

	int operator [] ( size_t pos ) const;

	bool operator == ( const HugeInteger &hir ) const;
	bool operator != ( const HugeInteger &hir ) const;
	bool operator > ( const HugeInteger &hir ) const;
	bool operator >= ( const HugeInteger &hir ) const;
	bool operator < ( const HugeInteger &hir ) const;
	bool operator <= ( const HugeInteger &hir ) const;

	size_t getSize() const { return size; }

	static int SUCCESS;
	static int FILE_PROBLEM;
	static int INVALID_DIGIT;

private:
	int *arr;
	size_t size;
	static const size_t DEFAULTSIZE;

	bool resize( size_t );
	bool resize();
	size_t firstNonZeroPos() const;
	void initialize();
};

ostream & operator << ( ostream &out, const HugeInteger &hi );




