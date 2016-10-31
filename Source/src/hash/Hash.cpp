#include <hash/Hash.h>

Hash::Hash() :
stack(),
clen(0),
key()
{}

Hash::~Hash(){
    stack.clear();
    clen = 0;
}

std::string Hash::digest(){
    return unhexlify(hexdigest());
}



