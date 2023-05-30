<template>
    <div>
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>Zeitdauer</th>
            <th>Visuelle Darstellung</th>
            <th>Aktionen</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(recipe, index) in recipes" :key="index">
            <td>
              <input
                type="text"
                v-model="recipe.name"
                :disabled="!recipe.editable"
              />
            </td>
            <td>
              <input
                type="time"
                v-model="recipe.duration"
                :disabled="!recipe.editable"
              />
            </td>
            <td>
              <div v-if="recipe.editable">
                <div :ref="`blocklyContainer-${index}`"></div>
                <button @click="saveBlocklyXml(index)">
                  Speichern
                </button>
              </div>
              <div v-else>
                <div :ref="`blocklyViewContainer-${index}`"></div>
                <button @click="editRecipe(index)">
                  Bearbeiten
                </button>
              </div>
            </td>
            <td>
              <button @click="deleteRecipe(index)">
                Löschen
              </button>
            </td>
          </tr>
        </tbody>
      </table>
  
      <button @click="addRecipe">
        Rezept hinzufügen
      </button>
    </div>
  </template>
  
  <script>
  import Blockly from 'blockly';
  
  export default {
    data() {
      return {
        recipes: [],
        blocklyWorkspaces: [],
      };
    },
    mounted() {
      this.initBlockly();
    },
    methods: {
      initBlockly() {
        this.recipes.forEach((recipe, index) => {
          const containerId = `blocklyContainer-${index}`;
          this.$nextTick(() => {
            const blocklyContainer = document.getElementById(containerId);
            if (blocklyContainer) {
              const workspace = Blockly.inject(blocklyContainer, {
                toolbox: document.getElementById('toolbox'),
                trashcan: true,
              });
              this.blocklyWorkspaces[index] = workspace;
            }
          });
        });
      },
      addRecipe() {
        this.recipes.push({
          name: '',
          duration: '',
          editable: true,
          blocklyXml: '',
        });
      },
      deleteRecipe(index) {
        this.recipes.splice(index, 1);
        this.blocklyWorkspaces.splice(index, 1);
      },
      editRecipe(index) {
        this.recipes[index].editable = true;
        this.blocklyWorkspaces[index].clear();
        Blockly.Xml.domToWorkspace(
          Blockly.Xml.textToDom(this.recipes[index].blocklyXml),
          this.blocklyWorkspaces[index]
        );
      },
      saveBlocklyXml(index) {
        const xml = Blockly.Xml.workspaceToDom(this.blocklyWorkspaces[index]);
        const xmlText = Blockly.Xml.domToText(xml);
        this.recipes[index].blocklyXml = xmlText;
        this.recipes[index].editable = false;
      },
    },
  };
  </script>
  