public class Aluno{
    private String matricula;
    private double p1;
    private double p2;
    public Aluno(String m){
        matricula = m;
    }

    public String getMatricula() {
        return matricula;
    }
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public double getP1() {
        return p1;
    }
    public void setP1(double p1) {
        this.p1 = p1;
    }

    public double getP2() {
        return p2;
    }
    public void setP2(double p2) {
        this.p2 = p2;
    }

    //    public Aluno(String m){
//        matricula = m;
//    }
    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Aluno){
            Aluno k = (Aluno) obj;
            return matricula.equals(k.matricula);
        }
        return false;
    }
}
