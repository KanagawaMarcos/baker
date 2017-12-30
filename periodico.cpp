periodico* createPeriodico(char* issn, char* name, char*area, char* qualis){
  periodico* newPeriodico = NULL;
  newPeriodico = new periodico[1];

  if(newPeriodico != NULL){
    newPeriodico->issn = issn;
    newPeriodico->name = name;
    newPeriodico->area = area;
    newPeriodico->qualis = qualis;

    newPeriodico->value = qualisValue(qualis);
    newPeriodico->left = NULL;
    newPeriodico->right = NULL;
  }

  return newPeriodico;
}
