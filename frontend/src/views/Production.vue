
<template>
    <div>
    <h2>Production</h2>
    <table>
      <thead>
        <tr>
          <th>Order Nr.</th>
          <th>Anzahl</th>
          <th>Zieldatum</th>
          <th>Rezept</th>
          <th>Status</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="(row, index) in rows" :key="index">
          <td>{{ row.text }}</td>
          <td>{{ row.number }}</td>
          <td>{{ row.date }}</td>
          <td>{{ row.recipe }}</td>
          <td>
            <select v-model="row.status" :disabled="row.edited">
              <option value="Geplant">Geplant</option>
              <option value="in Produktion">in Produktion</option>
              <option value="Pausiert">Pausiert</option>
              <option value="Fertig">Fertig</option>
              <option value="Abgebrochen">Abgebrochen</option>
            </select>
          </td>
        </tr>
      </tbody>
    </table>

    <div>
      <label>Order Nr.: </label>
      <input type="text" v-model="newRow.text" :disabled="editMode" />
    </div>

    <div>
      <label>Anzahl: </label>
      <input type="number" v-model="newRow.number" :disabled="editMode" />
    </div>

    <div>
      <label>Zieldatum: </label>
      <input type="date" v-model="newRow.date" :disabled="editMode" />
    </div>

    <div>
      <label>Rezept: </label>
      <select v-model="newRow.recipe" :disabled="editMode">
        <option v-for="recipe in recipes" :value="recipe" :key="recipe">
          {{ recipe }}
        </option>
      </select>
    </div>

    <div>
      <label>
        Status:
        <input
          type="checkbox"
          v-model="newRow.status"
          value="Geplant"
          :disabled="editMode"
        />
        Geplant
      </label>
      <label>
        <input
          type="checkbox"
          v-model="newRow.status"
          value="in Produktion"
          :disabled="editMode"
        />
        in Produktion
      </label>
      <label>
        <input
          type="checkbox"
          v-model="newRow.status"
          value="Pausiert"
          :disabled="editMode"
        />
        Pausiert
      </label>
      <label>
        <input
          type="checkbox"
          v-model="newRow.status"
          value="Fertig"
          :disabled="editMode"
        />
        Fertig
      </label>
      <label>
        <input
          type="checkbox"
          v-model="newRow.status"
          value="Abgebrochen"
          :disabled="editMode"
        />
        Abgebrochen
      </label>
    </div>

    <button @click="addRow" :disabled="editMode">Zeile hinzufügen</button>
    <button @click="toggleEditMode">
      {{ editMode ? "Bearbeiten beenden" : "Bearbeiten starten" }}
    </button>
  </div>
  </template>
<script>
export default {
  data() {
    return {
      rows: [], // Array, um die eingetragenen Zeilen zu speichern
      newRow: {
        text: '',
        number: null,
        date: null,
        recipe: '',
        status: [],
        edited: false,
      }, // Objekt, um eine neue Zeile einzugeben
      editMode: false, // Variable, um den Bearbeitungsmodus zu steuern
      recipes: ['Rezept 1', 'Rezept 2', 'Rezept 3'], // Array mit Rezepten für die Auswahlliste
    };
  },
  methods: {
    addRow() {
      this.rows.push({ ...this.newRow }); // Neue Zeile zum Array hinzufügen
      this.resetNewRow(); // Eingabemaske zurücksetzen
    },
    resetNewRow() {
      this.newRow = {
        text: '',
        number: null,
        date: null,
        recipe: '',
        status: [],
        edited: false,
      };
    },
    toggleEditMode() {
      this.editMode = !this.editMode; // Bearbeitungsmodus umschalten
    },
  },
};
</script>