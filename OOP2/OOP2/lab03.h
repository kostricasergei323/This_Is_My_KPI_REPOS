#pragma once
#ifndef  GRAPHICCARD_H
#define GRAPHICCARD_H

class GraphicCard
{
private:
  char *model;
  int VideoMemory;
  char *TypeOfVideoMemory;
  int GPU_Frequency;
  int VideoMemoryFrequency;
  int *Array;
  bool status = false;
  bool control = false;
public:
  GraphicCard();
  GraphicCard(const GraphicCard &);
  GraphicCard(char *, int , char* , int , int , int *);
  void ShowMainMenu();
  void DataOutput();
  void InitAll();
  char* getModel();
  int getVideoMemory();
  int getGPU_Frequency();
  bool getControl();
  char* getTypeOFVideoMemory();
  int getVideoMemoryFrequency();
  int* getArray();
  void ArrayInit(int*);
  GraphicCard operator+(GraphicCard&);
  bool operator>(const GraphicCard &) const;
  bool operator<(GraphicCard &) const;
  operator int() const;
  operator char*() const;
  ~GraphicCard();
};
#endif // GRAPHICCARD_H