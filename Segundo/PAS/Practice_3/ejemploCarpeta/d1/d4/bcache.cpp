//! This software is released under GNU GPL v2, see LICENSE file for details
//! (C) NECLA [bof] bcache.cpp
//! (contiguous) block cache with oldest-used drop strategy

#include <map>
#include "svm/bcache.hpp"

using namespace std;
using namespace MILDE;

struct Access
{
  Access( uint4 r, uint4 c ) : req(r), col(c) {}
  uint4 req;
  uint4 col;
};

bool operator<( const Access& x, const Access& y ) { return x.req > y.req; }

void Bcache::print_access() const
{
  typedef map<uint4, uint4> MMuint4;

  MMuint4 acc;
  
  for ( uint4 i = 0, n = d_reqs.size(); i != n; ++i ) {
    MMuint4::iterator it = acc.find( d_reqs[i] );
    if ( it == acc.end() ) { acc[d_reqs[i]] = 1; } else { ++acc[d_reqs[i]]; }
  }
  GAS.out(1) << "Vectors Accessed:" << endl;
  for ( MMuint4::const_reverse_iterator it = acc.rbegin(), hi =acc.rend(); it != hi; ++it ) {
    GAS.out(1) << setw(7) << it->second << ' ' << setw(8) << it->first << setw(0) << endl;
  }
}

void Bcache::clear_pcts()
{
  d_hit = d_mis = d_ini = 0;
}

void Bcache::clear_stat()
{
  clear_pcts();
  d_reqs.resize( d_index ); for ( uint4 i = 0; i != d_index; ++i ) d_reqs[i] = 0;
  d_reqs_uniq = 0;
}

//! (C) NECLA [eof] bcache.cpp
