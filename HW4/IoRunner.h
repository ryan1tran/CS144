#ifdef __cplusplus
#ifndef IORUNNER_H
#define IORUNNER_H

#include "FileIO.h"

class IoRunner : public FileIO
{
    public:
        IoRunner();
        std::vector<NoodleReview> read_from_file(std::string file_name) override;
        int write_to_file(std::string file_name, std::vector<NoodleReview> input_data) override;
};

#endif
#endif