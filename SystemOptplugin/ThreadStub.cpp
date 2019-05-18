#include "ThreadStub.h"
#include "RunItemFind.h"
#include "LoadWaitDialog.h"
ThreadStub::ThreadStub(void)
{
}

ThreadStub::~ThreadStub(void)
{
}

void ThreadStub::run ()
{

  RunItemFind::Instance()->FindStartItem();
  emit NotifyFindItem();
  
}