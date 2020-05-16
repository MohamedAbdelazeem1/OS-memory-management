#include "memory_management.h"
using namespace std;


vector<vector<string>> painting()
{
    vector<vector<string>>paint;
    for (int i = 1;i < memory.size();i++)
    {
        vector<string>temp;
        int size = 1;
        while (i < memory.size() && memory.at(i).at(1) == memory.at(i - 1).at(1) && memory.at(i).at(0) == memory.at(i - 1).at(0))
        {
            size++;
            i++;
        }
        temp.push_back(memory.at(i - 1).at(0));
        temp.push_back(memory.at(i - 1).at(1));
        temp.push_back(to_string(i - size));
        temp.push_back(to_string(size));
        paint.push_back(temp);
    }

    return paint;
}

void initializeMemory(std::string size)
{
    int my_size = std::atoi(size.c_str());
    memory.resize(my_size);
    for (auto& i : memory)
    {
        vector<string>temp;
        i.push_back(" ");
        i.push_back("NA");
    }

}

std::vector<std::vector<std::string>> setHoles(const std::vector<std::vector<std::string>>& x)
{

    for (auto& j : x)
    {
        int base = std::atoi(j[1].c_str());
        int size = std::atoi(j[2].c_str());
        while (size--)
        {
            memory[base][0] = " ";
            memory[base++][1] = "Hole";
        }

    }
    return painting();

}

std::vector<std::vector<std::string>> deleteProcess(std::string name)
{
    for (auto& i : memory)
    {
        if (i[0] == name)
        {
            i[0] = " ";
            i[1] = "Hole";
        }
    }

    return painting();

}

vector<vector<string>> BestFit(vector<vector<string>>& memory,vector<vector<string>>& segment_table ,vector<vector<string>>&notSizeProcess)
{
    for (int counter = 0;counter < segment_table.size();counter++)
    {
        string process_name = segment_table.at(counter).at(0), segment_name = segment_table.at(counter).at(1);
        int seg_size = stoi(segment_table.at(counter).at(2));
        int best_index, best_size;
        vector<vector<int>>holes_ranking;
        notSize = 1;
        for (int i = 0;i < memory.size();i++)
        {
            int hole_size = 0;
            while (i < memory.size() && memory.at(i).at(1) == "Hole")    //count the hole size*****
            {
                hole_size++;
                i++;
            }
            vector<int>temp;
            if (hole_size >= seg_size)
            {
                temp.push_back(hole_size);          //size of the current hole
                temp.push_back(i - hole_size);  //the index of the current hole
                holes_ranking.push_back(temp);
            }
        }
        if (holes_ranking.empty())
        {
            notSize = 0;
            //--------------modifying ----------------
            notSizeProcess.resize(segment_table.size());
                    for(int i=0;i<segment_table.size();i++){
                        notSizeProcess[i].push_back(segment_table[i][0]);
                        notSizeProcess[i].push_back(segment_table[i][1]);
                        notSizeProcess[i].push_back(segment_table[i][2]);
                    }
            //-------------------------
            return deleteProcess(process_name);
        }
        sort(holes_ranking.begin(), holes_ranking.end());
        best_size = holes_ranking.at(0).at(0);
        best_index = holes_ranking.at(0).at(1);
        for (int i = best_index;i < best_index + seg_size;i++)
        {
            memory.at(i).at(0) = process_name;
            memory.at(i).at(1) = segment_name;
        }
        //*******************************
    }
    segment_table.clear();

   return painting();

}

vector<vector<string>> FirstFit(vector<vector<string>>& memory,vector<vector<string>>& SegmentTeble ,vector<vector<string>>&notSizeProcess) {

    //vector<vector<string>>out;
    int hole_size;
    int pre, next = 0;
    // static int segment_rows = 0;
    notSize = 0;

    for (int i = 0;i < SegmentTeble.size();i++) {
        hole_size = 0;
        pre = 0;

        for (int k = pre;k < memory.size();k++) {

            if (memory[k][1] == "Hole") {
                pre++;

                hole_size = hole_size + 1;   //block size = 1

                if (stof(SegmentTeble[i][2]) <= hole_size) {

                    next = k;

                    for (int j = (k - hole_size) + 1;j < k + 1;j++) {
                        memory[j][1] = SegmentTeble[i][1];
                        memory[j][0] = SegmentTeble[i][0];

                    }
                    pre = next + 1;
                    notSize = 1;
                    hole_size=0;
                    break;
                }
                notSize = 0;

            }
            else{hole_size=0;}
        }
        if (notSize == 0) {
            /* not found fit size  proses not enter to memory   */

            //---------------   modifying  --------------
                           notSizeProcess.resize(SegmentTeble.size());
                           for(int i=0;i<SegmentTeble.size();i++){
                           notSizeProcess[i].push_back(SegmentTeble[i][0]);
                           notSizeProcess[i].push_back(SegmentTeble[i][1]);
                           notSizeProcess[i].push_back(SegmentTeble[i][2]);
                                }
            //-----------------------------
                           for (auto& m : memory)
                           {
                               if (m[0] == SegmentTeble[i][0])
                               {
                                   m[0] = " ";
                                   m[1] = "Hole";
                               }
                            }

           //memory= deleteProcess(SegmentTeble[i][0]); //  ---<
           break;
        }
    }
    // segment_rows = SegmentTeble.size();
    SegmentTeble.clear();
    return painting();


}

std::vector<std::vector<std::string>> showProcess(std::vector<std::vector<std::string>> segments,std::string process_name)
{
    std::vector<std::vector<std::string>> result;
    for (auto& i : segments)
    {
        if (i[0] == process_name)
                {
                    result.resize(result.size() + 1);
                    result[result.size() - 1].push_back(i[0]);
                    result[result.size() - 1].push_back(i[1]);
                    result[result.size() - 1].push_back(i[2]);
                    result[result.size() - 1].push_back(i[3]);
                }
    }
    return result;
}
