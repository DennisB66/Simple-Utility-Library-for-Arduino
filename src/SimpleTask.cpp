// Copyright  : Dennis Buis (2017)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleTask.cpp
// Purpose    : Simple library for task management
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#include <Arduino.h>
#include "SimpleTask.h"
#include "SimplePrint.h"

// create task
SimpleTask::SimpleTask( TaskFunc func, unsigned int freq)
{
  _func = func;                                             // task callback function
  _freq = max( 1, freq);                                    // task frequency
  _next = NULL;                                             // next task
}

// return task callback function
TaskFunc SimpleTask::func()
{
  return _func;
}

// return task frequency
unsigned int SimpleTask::freq()
{
  return _freq;
}

// return next task
SimpleTask* SimpleTask::next()
{
  return _next;
}

// set task calllback function
void SimpleTask::setFunc( TaskFunc func)
{
  _func = func;
}

// set next task
void SimpleTask::setNext( SimpleTask* task)
{
  _next = task;
}

/****************************************************************************/

// create (empty) task list
SimpleTaskList::SimpleTaskList()
{
  _rootTask = NULL;
}

// insert callback function
void SimpleTaskList::attachHandler( TaskFunc func)
{
  SimpleTask* task = new SimpleTask( func);                 // create new task entry

  _attach( task);                                           // insert task entry into list
}

// delete calback function
void SimpleTaskList::detachHandler( TaskFunc func)
{
  SimpleTask* task = _rootTask;                             // start with first task in list

  while ( task) {                                           // if task exists
    if ( func == task->func()) {                            // if callack function found
      _detach( task);                                       // delete task from list
    }
    delete task;                                            // delete task
    task = task->next();                                    // next task in list
  }
}

// print task list
void SimpleTaskList::print()
{
  SimpleTask* next = _rootTask;
  int         step = 0;

  Serial.print  ( F( "print start"));
  while ( next != NULL) {
    Serial.print( F( "/step "));
    Serial.print(  step++);
    next = next->next();
  }
  Serial.println( F( "/stop"));
}

// insert task into task list
void SimpleTaskList::_attach( SimpleTask* task)
{
  if ( _rootTask) {                                         // if first task exists
    _lastTask->setNext( task);                              // attach to last task
  } else {
    _rootTask = task;                                       // set first task
  }

  _lastTask = task;                                         // set last task pointer
}

// delete task from task list
void SimpleTaskList::_detach( SimpleTask* task)
{
  SimpleTask* curr = _rootTask;                             // task pointer = first task
  SimpleTask* next = task->next();                          // keep tail of task list

  if ( task == curr) {                                      // if first task to be deleted
    _rootTask = next;                                       // set new first task
  } else {
    while ( curr) {                                         // if task pointer still valid
      next = curr->next();                                  // keep tail of task list
      if ( task == next) {                                  // if task to be deleted
        curr->setNext( next->next());                       // set new next task
      }
      curr = next;                                          // goto next task
    }
  }
}

// execute all tasks in task list
void SimpleTaskList::_handle()
{
  SimpleTask* curr = _rootTask;                             // task pointer = first task
  TaskFunc    func;                                         // callback pointer

  while ( curr) {                                           // if task pointer still valid
    func = curr->func();                                    //
    ( *func)();                                             // execute callback function
    curr = curr->next();                                    // goto next task
  }
}
