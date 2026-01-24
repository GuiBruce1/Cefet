public class GerenciadorDeImpostoDeRenda{

        private double totalTributos = 0.0;

        public void adiciona(Tributavel t) {
            totalTributos += t.calculaTributos();
        }

        public void adiciona(Tributavel[] t) {
            for (Tributavel tributo : t) {
                if (tributo != null) {
                    totalTributos += tributo.calculaTributos();
                }
            }
        }

        public double getTotal() {
            return totalTributos;
        }
}


