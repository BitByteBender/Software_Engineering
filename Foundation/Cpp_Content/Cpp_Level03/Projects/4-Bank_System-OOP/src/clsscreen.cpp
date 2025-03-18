#include "../headers/clsscreen.hpp"

void clsScreen::_DrawScreenHeader(string Title, string Subtitle)
{
  cout<<clsUtil::Tabs(5)<<"______________________________________\n\n";
  cout<<clsUtil::Tabs(5)<<"   "<<Title;

  if (Subtitle != "")
    cout<<'\n'<<clsUtil::Tabs(5)<<"   "<<Subtitle;
  cout<<'\n'<<clsUtil::Tabs(5)<<"______________________________________\n\n";
}
