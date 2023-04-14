
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;

class Animal {
protected:
    string nickname;
    double speed;
public: 
    Animal(string nickname, double speed);
    Animal(string nickname);
    string get_name();
    void set_nickname(string nickname);
    double get_speed();
    void set_speed(double speed);
    double run(double acceleration, double distance);
    virtual void start_run(double distance) = 0;
    virtual void animal_feature(double time, double& currentDistance) = 0;
    void sleep(int msec);
};

class Horse : public Animal {
public:
    Horse(string nickname, double speed);
    Horse(string nickname);
    void start_run(double distance) override;
    void animal_feature(double time, double& currentDistance);
};

class Cheetah : public Animal {
public:
    Cheetah(string nickname, double speed);
    Cheetah(string nickname);
    void start_run(double distance) override;
    void animal_feature(double time, double& currentDistance);
};

class Gazelle : public Animal {
public:
    Gazelle(string nickname, double speed);
    Gazelle(string nickname);
    void start_run(double distance) override;
    void animal_feature(double time, double& currentDistance);
};

class Ostrich : public Animal {
public:
    Ostrich(string nickname, double speed);
    Ostrich(string nickname);
    void start_run(double distance) override;
    void animal_feature(double time, double& currentDistance);
};

class Hound : public Animal {
public:
    Hound(string nickname, double speed);
    Hound(string nickname);
    void start_run(double distance) override;
    void animal_feature(double time, double& currentDistance);
};

class Competition {
    vector<Animal*> participants;
    vector<string> winners;
    double distance;
public:
    Competition(double distance);
    Competition();
    void startCompetition();
    void addParticipant(Animal* animal);
    void printWinnersList();
    void set_distance(double distance);
    double get_distance();
};
////////////////////////////////////////////////////////////////

    Animal::Animal(string nickname, double speed) {
        this->nickname = nickname;
        this->speed = speed;
    }
    Animal::Animal(string nickname) {
        this->nickname = nickname;
    }
    string Animal:: get_name() {
        return nickname;
    }
    void Animal::set_nickname(string nickname) {
        this->nickname = nickname;
    }
    double Animal::get_speed() {
        return speed;
    }
    void Animal::set_speed(double speed) {
        this->speed = speed;
    }
    double Animal::run(double acceleration, double distance) {
        double currentDistance = 0.0;
        double currentSpeed = 0.0;
        double time = 0.0;
        while (currentDistance < distance) {
            if (speed + acceleration * time <= speed)
                currentSpeed = speed + acceleration * time;
            currentDistance += currentSpeed;
            time += 1.0;
            animal_feature(time, currentDistance);
            sleep(1000);
        }
        return time;
    }

    void Animal::sleep(int msec) {
        std::chrono::milliseconds time(msec);
        std::this_thread::sleep_for(time);
    }
////////////////////////////////////////////////////////////////
    
    Horse::Horse(string nickname, double speed) :Animal(nickname, speed) {}

    Horse::Horse(string nickname) : Animal(nickname) { speed = 19.0; }

    void Horse::start_run(double distance) {
        sleep(1000);
        cout << "Лошадь " << nickname << " стартует" << endl;
        double time = run(1.0, distance);
        cout << "----- Лошадь " << nickname << " пробежала за " << time << " секунд -----" << endl;
    }

    void Horse::animal_feature(double time, double& currentDistance) {
        if (int(time) % 30 == 0) {
            double jumpMeters = (double) rand() / RAND_MAX * (8 - 3) + 3;
            currentDistance += jumpMeters;
            cout << " Лошадь " << nickname << " совершает прыжок на " << jumpMeters << " метров!" << endl;
        }
    }

////////////////////////////////////////////////////////////////
    Cheetah::Cheetah(string nickname, double speed) :Animal(nickname, speed) {}
    Cheetah::Cheetah(string nickname) : Animal(nickname) { speed = 30.0; }
    void Cheetah::start_run(double distance)  {
        sleep(1250);
        cout << "Гепард " << nickname << " стартует" << endl;
        double time = run(1.5, distance);
        cout << "----- Гепард " << nickname << " пробежал за " << time << " секунд -----" << endl;
    }
    void Cheetah::animal_feature(double time, double& currentDistance) {
        if (int(time) % 20 == 0) {
            int jumpTimes = rand() / RAND_MAX * (4 - 2) + 2;
            for (int i = 0; i < jumpTimes; i++)
            {
                double jumpMeters = (double)rand() / RAND_MAX * (8 - 6) + 6;
                cout << " Гепард " << nickname << " совершает прыжок на " << jumpMeters << " метров!" << endl;
                currentDistance += jumpMeters;
                sleep(500);
            }
        }
    }

////////////////////////////////////////////////////////////////

    Gazelle::Gazelle(string nickname, double speed) :Animal(nickname, speed) {}
    Gazelle::Gazelle(string nickname) : Animal(nickname) { speed = 28.0; }
    void Gazelle::start_run(double distance) {
        sleep(1500);
        cout << "Газель " << nickname << " стартует" << endl;
        double time = run(1.2, distance);
        cout << "----- Газель " << nickname << " пробежала за " << time << " секунд -----" << endl;
    }
    void Gazelle::animal_feature(double time, double& currentDistance) {
        if (int(time) % 40 == 0) {
            cout << " Газель " << nickname << " остановилась!" << endl;
            int timeToSleep = rand() / RAND_MAX * (4000 - 1000) + 1000;
            sleep(timeToSleep);
            cout << " Газель " << nickname << " продолжает движение!" << endl;
        }
    }

////////////////////////////////////////////////////////////////

    Ostrich::Ostrich(string nickname, double speed) :Animal(nickname, speed) {}
    Ostrich::Ostrich(string nickname) : Animal(nickname) { speed = 23.0; }
    void Ostrich::start_run(double distance) {
        sleep(1750);
        cout << "Страус " << nickname << " стартует" << endl;
        double time = run(1.3, distance);
        cout << "----- Страус " << nickname << " пробежал за " << time << " секунд -----" << endl;
    }
    void Ostrich::animal_feature(double time, double& currentDistance) {
        if (int(time) % 25 == 0) {
            double jumpMeters = (double)rand() / RAND_MAX * (4 - 3) + 3;
            cout << " Страус " << nickname << " совершает прыжок на " << jumpMeters << " метров!" <<endl;
            cout << " Страус " << nickname << " упал!" << endl;
            int timeToSleep = rand() / RAND_MAX * (4000 - 2500) + 2500;
            sleep(timeToSleep);
            cout << " Страус " << nickname << " продолжает движение!" << endl;
        }
    }

////////////////////////////////////////////////////////////////

    Hound::Hound(string nickname, double speed) :Animal(nickname, speed) {}
    Hound::Hound(string nickname) : Animal(nickname) { speed = 16.0; }
    void Hound::start_run(double distance) {
        sleep(2000);
        cout << "Собака " << nickname << " стартует" << endl;
        double time = run(0.8, distance);
        cout << "----- Собака " << nickname << " пробежала за " << time << " секунд -----" << endl;
    }
    void Hound::animal_feature(double time, double& currentDistance) {
        if (int(time) % 35 == 0) {
            cout << " Собака " << nickname << " развернулась и побежала в обратном направлении! " << endl;
            double reverseRunMeters = rand() / RAND_MAX * (50 - 30) + 30;
            sleep(int(reverseRunMeters / speed * 1000));
            currentDistance -= reverseRunMeters;
            cout << " Собака " << nickname << " продолжает движение в правильном направлении! " << endl;
        }
    }

////////////////////////////////////////////////////////////////

    Competition::Competition(double distance) {
        this->distance = distance;
    }
    Competition::Competition() {}
    void Competition::startCompetition() {
        if (!distance) {
            cout << "Не указана дистанция!" << endl;
            return;
        }
        winners.clear();
        vector <thread> threads;
        for (int i = 0; i < participants.size(); i++)
        {
            threads.emplace_back([&](Animal* animal, double distance) {
                animal->start_run(distance);
                winners.push_back(animal->get_name());
                }, participants[i], distance);
        }
        for (auto& thread : threads) {
            thread.join();
        }
        printWinnersList();
    }
    void Competition::addParticipant(Animal* animal) {
        participants.push_back(animal);
    }
    void Competition::printWinnersList() {
        cout << endl << "----- Список победителей -----" << endl;
        for (int i = 0; i < winners.size(); i++)
        {
            cout << " - " << i + 1 << ". " << setw(12) << winners[i] << " - " << endl;
        }
        cout << endl;
    }

    void Competition::set_distance(double distance) {
        this->distance = distance;
    }
    
    double Competition::get_distance() {
        return distance;
    }

////////////////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "Russian");
    Horse h("Horse");
    Cheetah c("Cheetah");
    Gazelle g("Gazelle");
    Ostrich o("Ostrich");
    Hound ho("Hound");

    double distance;
    cout << "Введите дистанцию для соревнования (в метрах): ";
    cin >> distance;

    Competition competition(distance);
    competition.addParticipant(&h);
    competition.addParticipant(&c);
    competition.addParticipant(&g);
    competition.addParticipant(&o);
    competition.addParticipant(&ho);

    competition.startCompetition();
}
