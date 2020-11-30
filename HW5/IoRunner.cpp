#include "IoRunner.h"

IoRunner::IoRunner()
{
    std::cout << "FileIO class object has started." << std::endl;
}

LinkedList IoRunner::read_from_file(std::string file_name)
{
    LinkedList reviews;

    std::ifstream read_file(file_name);
    std::string rdata;

    std::string comma_token(",");

    getline(read_file, rdata); // removes first line that has no data

    while (getline(read_file, rdata))
    {
        std::size_t found = rdata.find(comma_token);

        if (found != std::string::npos) {
            std::stringstream s_stream(rdata);
            std::vector<std::string> vec_data;

            while (s_stream.good())
            {
                std::string sub_string;
                getline(s_stream, sub_string, ',');
                vec_data.push_back(sub_string);
            }

            if (vec_data.at(5) == "Unrated")
                vec_data.at(5) = "-1.0";

            if (vec_data.at(6) == "\"")
                vec_data.at(6) = "";

            reviews.add_data(new NoodleReview(std::stoi(vec_data.at(0)), vec_data.at(1), vec_data.at(2), vec_data.at(3), vec_data.at(4), std::stod(vec_data.at(5)), vec_data.at(6)));
        }
    }

    read_file.close();

    return reviews;
}

int IoRunner::write_to_file(std::string file_name, LinkedList input_data)
{
    std::ofstream new_file(file_name);

    if (!new_file.is_open())
        return -1;

    Node* current = input_data.get_head();
    while (current != nullptr)
    {
        new_file << assemble_noodle_review(*current->get_data()) << std::endl;
        current = current->get_next_node();
    }

    new_file.close();

    return 0;
}