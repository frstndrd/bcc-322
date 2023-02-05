/**
 * @file system.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Describes the system class
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <ostream>

using namespace std;

/**
 * @brief Define the interface with the methods to be implemented
 * 
 */
class System {
    protected:
        /**
         * @brief Name the system
         * 
         */
        string name;
        /**
         * @brief Store a value for the system
         * 
         */
        float value;

    public:
        /**
         * @brief Empty constructor of the class
         * 
         */
        System();
        /**
         * @brief Construct a new System object
         * 
         * @param name of the system
         */
        System(const string name);
        /**
         * @brief Construct a new System object
         * 
         * @param value to be contained in that system
         */
        System(float value);
        /**
         * @brief Copy a System object
         * 
         * @param obj system to be copied
         */
        System(System& obj);
        /**
         * @brief Assigns name and value to a system
         * 
         * @param name assigned to the system
         * @param value assigned to the system
         */
        System(const string name, float value);
        /**
         * @brief Destroy the System object
         * 
         */
        virtual ~System();

        /**
         * @brief Get the Name object
         * 
         * @return string The name of a system
         */
        string getName() const;
        /**
         * @brief Set the Name object
         * 
         * @param name the system
         */
        void setName(const string name);
        /**
         * @brief Get the Value object
         * 
         * @return float Value assigned to a system
         */
        float getValue() const;
        /**
         * @brief Set the Value object
         * 
         * @param value float value to be assigned to a system
         */
        void setValue(float value);

        /**
         * @brief Overload the '=' operator, cloning from one to the other
         * 
         * @param obj system to be cloned
         * @return System& A clone of the system
         */
        System& operator= (const System& obj);
};

#endif