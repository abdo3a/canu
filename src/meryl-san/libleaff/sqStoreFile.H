
/******************************************************************************
 *
 *  This file is part of canu, a software program that assembles whole-genome
 *  sequencing reads into contigs.
 *
 *  This software is based on:
 *    'Celera Assembler' (http://wgs-assembler.sourceforge.net)
 *    the 'kmer package' (http://kmer.sourceforge.net)
 *  both originally distributed by Applera Corporation under the GNU General
 *  Public License, version 2.
 *
 *  Canu branched from Celera Assembler at its revision 4587.
 *  Canu branched from the kmer project at its revision 1994.
 *
 *  Modifications by:
 *
 *  File 'README.licenses' in the root directory of this distribution contains
 *  full conditions and disclaimers for each license.
 */

#ifndef SQSTOREFILE_H
#define SQSTOREFILE_H

#include "seqFile.H"
#include "sqStore.H"

class sqStoreFile : public seqFile {
protected:
  sqStoreFile(const char *filename);
  sqStoreFile();

public:
  ~sqStoreFile();

protected:
  seqFile      *openFile(const char *name);

public:
  uint32        find(const char *sequencename) {
    fprintf(stderr, "sqStoreFile::find()--  Lookup of sequencename '%s' not supported.\n", sequencename);
    assert(0);
    return(0);
  };

  uint32        getSequenceLength(uint32 iid) {
    return(seq->sqStore_getRead(iid + 1)->sqRead_sequenceLength());
  };

  bool          getSequence(uint32 iid,
                            char *&h, uint32 &hLen, uint32 &hMax,
                            char *&s, uint32 &sLen, uint32 &sMax);
  bool          getSequence(uint32 iid,
                            uint32 bgn, uint32 end, char *s);

private:
  void          clear(void);

  sqStore      *seq;
  sqReadData    readData;

  friend class seqFactory;
};


#endif  //  SQSTOREFILE_H
