//Date test por Jonathan Iury

public class Date 
{
   private int mes; // 1-12
   private int dia;   // 1-31 conforme o m�s
   private int ano;  // qualquer ano

   // construtor: chama checkMes para confirmar o valor adequado para month;
   // chama checkDia para confirmar o valor adequado para day
   public Date( int theMes, int theDia, int theAno )
   {
      mes = checkMes( theMes ); // valida month
      ano = theAno; // poderia validar year
      dia = checkDia( theDia ); // valida day

      System.out.printf("Contrutor Objeto da data: %s\n", this );
   } // fim do construtor Date

   // m�todo utilit�rio para confirmar o valor adequado de month
   private int checkMes( int testMonth )
   {
      if ( testMonth > 0 && testMonth <= 12 ) // valida month
         return testMonth;
      else // month � inv�lido
      { 
         System.out.printf( 
            "Invalido mes (%d) vai pra 1.", testMonth );
         return 1; // mant�m objeto em estado consistente
      } // fim de else
   } // fim do m�todo checkMonth

   // m�todo utilit�rio para confirmar o valor adequado de day com base em month e year
   private int checkDia( int testDay, int mes, int ano )
   {
      int daysPerMonth[] = 
         { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   
      // verifica se day est� no intervalo para month
      if ( testDay > 0 && testDay <= daysPerMonth[ mes ] )
         return testDay;
   
      // verifica ano bissexto
      if ( mes == 2 && testDay == 29 && ( ano % 400 == 0 ||
           ( ano % 4 == 0 && ano % 100 != 0 ) ) )
         return testDay; //Este campo bissexto eu copiei da internet 
                        //para implementar o c�digo, eu n�o fiz.
   
      System.out.printf( "Dia Invalido (%d) configurar pra 1.", testDay );
      return 1;  // mant�m objeto em estado consistente
   } // fim do m�todo checkDay
   
   // retorna uma String no formato m�s/dia/ano
    @Override
   public String toString()
   { 
      return String.format( "%d/%d/%d", mes, dia, ano );
   } // fim do m�todo toString
} // fim da classe Date
