#ifdef __cplusplus
#ifndef FILEIO_H
#define FILEIO_H

#include "NoodleReview.h"

class FileIO
{
    virtual std::vector<NoodleReview> read_from_file(std::string file_name) = 0;
    virtual int write_to_file(std::string file_name, std::vector<NoodleReview> input_data) = 0;
};

#endif
#endif