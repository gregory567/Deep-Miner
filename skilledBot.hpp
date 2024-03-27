#ifndef SKILLEDBOT_HPP_INCLUDED
#define SKILLEDBOT_HPP_INCLUDED

class skilledBot: public Robot{
    public:
        skilledBot(std::string name);
        virtual ~skilledBot();

        void extract(Mine& m, const int x, const int y) override;


    protected:

    private:


};

#endif // SKILLEDBOT_HPP_INCLUDED
