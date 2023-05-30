<template>
  <div>
    <h2>Dasboard</h2>


    <div ref="chartContainer"></div>
    </div>
  </template>
  
  <script>
  import * as d3 from 'd3';
  
  export default {
    name: 'ChartComponent',
    props: {
      data: {
        type: Array,
        required: true,
      },
    },
    mounted() {
      this.drawChart();
    },
    methods: {
      drawChart() {
        // Containerelement für das Chart
        const container = d3.select(this.$refs.chartContainer);
  
        // Chart-Maße
        const width = 600;
        const height = 400;
  
        // Skalierungen für den X- und Y-Achsenbereich
        const xScale = d3.scaleLinear().range([0, width]);
        const yScale = d3.scaleBand().range([0, height]).padding(0.1);
  
        // Farbskala für die Auslastungswerte
        const colorScale = d3.scaleLinear().range(['lightgreen', 'darkgreen']);
  
        // Daten laden und verarbeiten
        const data = this.data.map((d) => ({
          period: d.period,
          utilization: d.utilization,
          color: d.color,
        }));
  
        // Domänen für die Skalierungen festlegen
        xScale.domain([0, d3.max(data, (d) => d.utilization)]);
        yScale.domain(data.map((d) => d.period));
        colorScale.domain(d3.extent(data, (d) => d.utilization));
  
        // SVG-Element erstellen
        const svg = container
          .append('svg')
          .attr('width', width)
          .attr('height', height);
  
        // Rechtecke für die Auslastung erstellen
        const rectangles = svg
          .selectAll('rect')
          .data(data)
          .enter()
          .append('rect')
          .attr('x', 0)
          .attr('y', (d) => yScale(d.period))
          .attr('width', (d) => xScale(d.utilization))
          .attr('height', yScale.bandwidth())
          .attr('fill', (d) => d.color);
  
        // Zoom-Funktionalität hinzufügen
        const zoom = d3.zoom().on('zoom', zoomed);
        svg.call(zoom);
  
        function zoomed() {
          const transform = d3.event.transform;
          rectangles.attr('transform', transform);
        }
      },
    },
  };
  </script>
  
  <style scoped>
  /* Stile für das Chart-Container-Element */
  div {
    width: 100%;
    height: 100%;
  }
  </style>
  

