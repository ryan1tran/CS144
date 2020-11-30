#ifdef __cplusplus
#ifndef FILEIO_H
#define FILEIO_H

#include "NoodleReview.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>

class FileIO
{
    virtual LinkedList read_from_file(std::string file_name) = 0;
    virtual int write_to_file(std::string file_name, LinkedList input_data) = 0;
};

#endif
#endif