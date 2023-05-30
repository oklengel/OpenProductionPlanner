<template>
    <div>
      <h2>Personalverwaltung</h2>
  
      <form @submit.prevent="addEmployee">
        <input type="text" v-model="newEmployeeName" placeholder="Name" required />
        <input type="text" v-model="newEmployeeQualification" placeholder="Qualifikation" required />
        <button type="submit">Mitarbeiter hinzufügen</button>
      </form>
  
      <ul>
        <li v-for="(employee, index) in employees" :key="index">
          <span>{{ employee.name }} - {{ employee.qualification }}</span>
          <button @click="removeEmployee(index)">Mitarbeiter entfernen</button>
        </li>
      </ul>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        newEmployeeName: '',
        newEmployeeQualification: '',
        employees: [],
      };
    },
    methods: {
      addEmployee() {
        if (this.newEmployeeName && this.newEmployeeQualification) {
          this.employees.push({
            name: this.newEmployeeName,
            qualification: this.newEmployeeQualification,
          });
          this.newEmployeeName = '';
          this.newEmployeeQualification = '';
        }
      },
      removeEmployee(index) {
        this.employees.splice(index, 1);
      },
    },
  };
  </script>
  