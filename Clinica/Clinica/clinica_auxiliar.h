typedef struct medico Medico;
typedef struct especialidade Especialidade;

int buscaEspec(Especialidade *nome); // retorna o indice
Medico *MedicoNaEspecialidade(Especialidade *nome, int num_especialidades, char *);