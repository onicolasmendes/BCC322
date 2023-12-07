#include "unit_handleBody.h"
#include <cstdlib>
#include <iostream>
#include <cstdlib>

using namespace std;

#define DEBUGING
#ifdef DEBUGING
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;
#endif

void unit_handleBody()
{
    // Apenas a implementacao da classe "Flux" precisa ser conhecida na
    // fase de "cria��o de objetos", pois o usu�rio precisa implementar
    // v�rios tipos de fluxo. Ent�o, o m�dulo de cria��o de objetos precisa
    // conhecer os fluxos implementados pelo usu�rio.No entanto, nenhuma outra
    // implementa��o precisa ser conhecida por qq outro m�dulo.
    // Cria modelo
    Model *model = Model::createModel("Modelo Exponencial");
    System *system1 = model->createSystem("s1", 20);
    System *system2 = model->createSystem("s2", 10);
    Flow *flow = model->createFlow<FlowExponencial>(system1, system2);

    // USANDO REFERENCIAS PARA INTERFACE (CLASSE ABSTRATA)
    // System& s1 = m.createSystem("populacao",10.0);
    // System& s2 = m.createSystem("Teste", 7.90)   ;
    // cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;
    // s1 = s2;  // nao funciona pq s1 � uma referencia, portanto nao pode ser redefinida
    // cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;

    cout << "s1: " << system1->getName() << ", s2: " << system2->getName() << endl;
    // s1 = s2;
    *system1 = *system2;
    cout << "s1: " << system1->getName() << ", s2: " << system2->getName() << endl;
    cout << "s1: " << system1 << ", s2: " << system2 << endl;

    // Fa�a o teste COM e SEM as chaves abaixo
    {
        // USANDO OBJETOS HANDLES (DELEGA��O)
        SystemHandle s3("tiago", 7), s4("antonio", 8);
        cout << "s3: " << s3.getName() << ", s2: " << s4.getName() << endl;
        s3 = s4; // comente esta linha e veja que o resultado muda
        cout << "s3: " << s4.getName() << ", s2: " << s4.getName() << endl;
        s3 = s3;
        cout << "s3: " << s4.getName() << ", s2: " << s4.getName() << endl;
    }
    assert(numHandleDeleted == 2);
    assert(numBodyDeleted == 2);

    assert(numHandleCreated == 6);
    assert(numBodyCreated == 6);

    // Monta Modelo
    // m.setTarget(f1, s1);
    // model->setSource(flow, system1);

    // executa o modelo
    // model->run(0,30);

    // imprime relatorio
    // cout << s1.getValue() << endl;
    cout << system1->getValue() << endl;

    // Deletes
    delete model;

    assert(numBodyDeleted == 6);
    assert(numHandleDeleted == 6);

    cout << "Created handles: " << numHandleCreated << endl;
    cout << "Deleted handles: " << numHandleDeleted << endl;
    cout << "Created bodies: " << numBodyCreated << endl;
    cout << "Deleted bodies: " << numBodyDeleted << endl;

    return;
}

void run_unit_test_handleBody()
{
    unit_handleBody();
}
