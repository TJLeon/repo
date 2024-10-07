#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const string argv) {
    int flag = -1;
    for (int i = 0; argv[i]; i++)
    {
        if (argv[i] == ' ')
            continue;
        if (argv[i] <= '0' || argv[i] > '9')
        {
            std::cerr << "Error: Invalid input" << std::endl;
            exit(1);
        }
        else
        {
            if (flag == -1)
            {
                deq.push_back(argv[i] - '0');
                vctr.push_back(argv[i] - '0');
            }
            else
            {
                deq.push_front(argv[i] - '0');
                vctr.insert(vctr.begin(), argv[i] - '0');
            }
            flag *= -1;
        }
    }
    deque<int>::iterator it = deq.begin();
    while (it != deq.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

PmergeMe::~PmergeMe() {
}
void PmergeMe::mergeVector()
{
    vector<int>::iterator it = vctr.begin();
    while(it != vctr.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    cout << "Sorting with vector" << endl;
    clock_t start_time = clock(); 
    while (!is_sorted(vctr))
    {
        // cout << "here" << endl;
        int size = deq.size();
        if (size % 2 != 0)
        {
            extraNum = vctr.back();
            vctr.pop_back();
        }
        for (int i = 0; i < size; i++)
        {
            if (!vctr.empty() && vctr.front() > vctr.back())
            {
                vctrBuffer.insert(vctrBuffer.begin(), vctr.back());
                vctr.pop_back();
                vctrBuffer.push_back(vctr.front());
                if (!vctr.empty())
                    vctr.erase(vctr.begin());
            }
            else if (!vctr.empty())
            {
                vctrBuffer.insert(vctrBuffer.begin(), vctr.front());
                vctr.erase(vctr.begin());
                vctrBuffer.push_back(vctr.back());
                if (!vctr.empty())
                    vctr.pop_back();
            }
        }
        std::vector<int>::iterator mid_it = vctrBuffer.begin();
        std::advance(mid_it, vctrBuffer.size() / 2); 
        std::sort(vctrBuffer.begin(), mid_it);
        if (size % 2 != 0)
        {
            vctrBuffer.push_back(extraNum);
            size++;
        }
        vector<int>::iterator it = vctrBuffer.begin();
        while(it != vctrBuffer.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        std::sort(mid_it, vctrBuffer.end());
        it = vctrBuffer.begin();
        while(it != vctrBuffer.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        // vctr = vctrBuffer;
        if (!is_sorted(vctrBuffer))
        {
            while (!vctrBuffer.empty())
            {
                int flag = -1;
                if (flag == -1)
                {
                    vctr.push_back(vctrBuffer.front());
                    vctrBuffer.erase(vctrBuffer.begin());
                }
                else
                {
                    vctr.insert(vctrBuffer.begin(), vctrBuffer.back());
                    vctrBuffer.pop_back();
                }
                flag *= -1;
            }
        }
        // vctrBuffer.clear();
    }
    clock_t end_time = clock(); 
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
      std::cout << "Time taken by function: " 
            << std::fixed << std::setprecision(10) << time_taken // Format output
            << " seconds" << std::endl;
}

void PmergeMe::mergeDeque() 
{
    cout << "Sorting with deque" << endl;
    clock_t start_time = clock(); 
    while (!is_sorted(deq))
    {
        int size = deq.size();
        if (size % 2 != 0)
        {
            extraNum = deq.back();
            deq.pop_back();
        }
        for (int i = 0; i < size; i++)
        {

            if (deq.front() > deq.back() && !deq.empty())
            {
                deqBuffer.push_front(deq.back());
                deq.pop_back();
                deqBuffer.push_back(deq.front());
                if (!deq.empty())
                    deq.pop_front();
            }
            else if (!deq.empty())
            {
                deqBuffer.push_front(deq.front());
                deq.pop_front();
                deqBuffer.push_back(deq.back());
                if (!deq.empty())
                    deq.pop_back();
            }
        }
        std::deque<int>::iterator mid_it = deqBuffer.begin();
        std::advance(mid_it, deqBuffer.size() / 2); 
        std::sort(deqBuffer.begin(), mid_it);
        if (size % 2 != 0)
        {
            deqBuffer.push_back(extraNum);
            size++;
        }
        deque<int>::iterator it = deqBuffer.begin();
        while(it != deqBuffer.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        std::sort(mid_it, deqBuffer.end());
        it = deqBuffer.begin();
        while(it != deqBuffer.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        if (!is_sorted(deqBuffer))
        {
            while (!deqBuffer.empty())
            {
                int flag = -1;
                if (flag == -1)
                {
                    deq.push_back(deqBuffer.front());
                    deqBuffer.pop_front();
                }
                else
                {
                    deq.push_front(deqBuffer.back());
                    deqBuffer.pop_back();
                }
                flag *= -1;
            }
        }
        deqBuffer.clear();
    }
    clock_t end_time = clock(); 
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
      std::cout << "Time taken by function: " 
            << std::fixed << std::setprecision(10) << time_taken // Format output
            << " seconds" << std::endl;
}